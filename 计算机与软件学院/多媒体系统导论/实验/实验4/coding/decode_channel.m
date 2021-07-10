%%file decode_channel.m
function img = decode_channel(htreefile, streamfile, parameter, imgsize, channel)
    %% 读取码流文件
    dict_d = readhtree(htreefile);
    bitstream_d = readstreamfile(streamfile);
    dhsig = huffmandeco(bitstream_d, dict_d);
    diffimg = reshape(dhsig, imgsize(1), imgsize(2));

    % 亮度亮度量化表
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

    if channel == 1
        diffimg = blkproc(diffimg, [8, 8], 'x.*P1', lighttable);
    else
        diffimg = blkproc(diffimg, [8, 8], 'x.*P1', colortable);
    end

    diffimg = blkproc(diffimg, [8, 8], 'idct2');

    img = zeros(imgsize);
    img = reshape(diffimg, imgsize(1), imgsize(2));

end
