%%file encode_channel.m
function [size_dict, size_bitstream] = encode_channel(img, htreefile, streamfile, parameter, channel)
    %% 信号源的统计特性分析
    % 亮度量化表
    lighttable = parameter * [16 11 10 16 24 40 51 61;
                    12 12 14 19 26 58 60 55;
                    14 13 16 24 40 57 69 56;
                    14 17 22 29 51 87 80 62;
                    18 22 37 56 68 109 103 77;
                    24 35 55 64 81 104 113 92;
                    49 64 78 87 103 121 120 101;
                    72 92 95 98 112 100 103 99];

    % 色度量化表
    colortable = parameter * [17 18 24 47 99 99 99 99;
                    18 21 26 66 99 99 99 99;
                    24 26 56 99 99 99 99 99;
                    47 66 99 99 99 99 99 99;
                    99 99 99 99 99 99 99 99;
                    99 99 99 99 99 99 99 99;
                    99 99 99 99 99 99 99 99;
                    99 99 99 99 99 99 99 99];

    dct = blkproc(img, [8, 8], 'dct2');

    if channel == 1
        sig = blkproc(dct, [8, 8], 'round(x./P1)', lighttable);
    else
        sig = blkproc(dct, [8, 8], 'round(x./P1)', colortable);
    end

    sig = double(sig(:));
    [prob, symbols] = hist(sig, [min(sig):1:max(sig)]); % compute the histogram.
    prob = prob / numel(sig);

    %% 赫夫曼编码
    dict = huffmandict(symbols, prob); %huffman tree
    bitstream = huffmanenco(sig, dict);
    %% 保存为码流文件（注意文件尺寸）
    size_dict = savehtree(htreefile, dict);
    size_bitstream = savestreamfile(streamfile, bitstream);
end
