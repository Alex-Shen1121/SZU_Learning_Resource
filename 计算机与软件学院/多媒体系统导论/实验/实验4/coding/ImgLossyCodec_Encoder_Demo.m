%%file ImgLossyCodec_Encoder_Demo.m
function ImgLossyCodec_Encoder_Demo(filename, ratio, parameter)
    %close all, clear all
    %% 读入待压缩图像原始数据
    %filename = 'data\\Lenna.png';
    %filename = 'data\\Weeki_Wachee_spring.jpg';
    img_rgb = imread(filename);
    img_rgb = imresize(img_rgb, 1 / ratio);
    [h, w, d] = size(img_rgb);

    if d > 1
        img_yuv = rgb2ycbcr(img_rgb);
    end

    % 码流存放路径
    stream_path = 'stream';

    if ~isdir(stream_path)
        mkdir(stream_path);
    end

    % 文件名解析
    [pathstr, name, ext] = fileparts(filename);

    %% 对图像的各个通道进行单独编码，每个通道输出htree.bin和stream.bin两个文件。
    tic
    size_dict = 0; % huffman tree的文件的大小(Byte)
    size_bitstream = 0; % 生成的码流文件的总大小(Byte)

    if d == 1
        htreefile = sprintf('%s\\%s_m%d_htree.bin', stream_path, name, parameter);
        streamfile = sprintf('%s\\%s_m%d_stream.bin', stream_path, name, parameter);

        [size_dict, size_bitstream] = encode_channel(img_rgb, htreefile, streamfile, parameter, 1);
    else

        for chl = 1:d
            htreefile = sprintf('%s\\%s_chl%d_m%d_htree.bin', stream_path, name, chl, parameter);
            streamfile = sprintf('%s\\%s_chl%d_m%d_stream.bin', stream_path, name, chl, parameter);
            [size_dict_chl, size_bitstream_chl] = encode_channel(img_yuv(:, :, chl), htreefile, streamfile, parameter, chl);
            size_dict = size_dict + size_dict_chl;
            size_bitstream = size_bitstream + size_bitstream_chl;
        end

    end

    disp(sprintf('Image Encoding Finshed'));
    disp(sprintf('Encoding time： %6.4f s', toc));
    disp(sprintf('Dict size： %d Bytes', size_dict));
    disp(sprintf('Code size： %d Bytes', size_bitstream));
    %%Calculation of compression ratio
    B0 = numel(img_rgb);
    B1 = size_dict + size_bitstream;
    compressionratio = B0 / B1;
    disp(sprintf('Orginal： %d Bytes; Compressed： %d Bytes; Compression ratio：%6.2f \r\n ----------------', B0, B1, compressionratio));
    %% 对图像的各个通道进行单独解码，每个通道首先解析相应的htree.bin文件，生成HuffmanTreeB0,再对stream.bin文件进行解码和重建。
    tic
    % size_dict=0; % 读取的huffman tree的文件大小(Byte)
    % size_bitstream=0; % 读取的码流文件的总大小(Byte)
    img_yuv_rec = zeros([h, w, d]);

    if d == 1
        htreefile = sprintf('%s\\%s_m%d_htree.bin', stream_path, name, parameter);
        streamfile = sprintf('%s\\%s_m%d_stream.bin', stream_path, name, parameter);
        img_rec = decode_channel(htreefile, streamfile, parameter, [h, w], 1);
    else

        for chl = 1:d
            htreefile = sprintf('%s\\%s_chl%d_m%d_htree.bin', stream_path, name, chl, parameter);
            streamfile = sprintf('%s\\%s_chl%d_m%d_stream.bin', stream_path, name, chl, parameter);
            img_yuv_rec_chl = decode_channel(htreefile, streamfile, parameter, [h, w], chl);
            img_yuv_rec(:, :, chl) = img_yuv_rec_chl;
        end

        img_yuv_rec = uint8(img_yuv_rec);
        img_rec = ycbcr2rgb(img_yuv_rec);
    end

    fprintf('Image Decoding Finshed\n');
    disp(sprintf('Decoding time： %6.4f s', toc));
    mse_yuv = sum((double(img_yuv(:)) - double(img_yuv_rec(:))).^2) / numel(img_yuv);
    mse_rgb = sum((double(img_rgb(:)) - double(img_rec(:))).^2) / numel(img_rgb);

    if mse_yuv
        disp('Image Lossy Compression Success!')
    else
        disp('Image Lossy Compression Failed!')
    end

    subplot(121), imshow(img_rgb), title(sprintf('original: %s', name))
    subplot(122), imshow(img_rec), title(sprintf('MSE YUV: %6.2f; RGB: %6.2f', mse_yuv, mse_rgb))
