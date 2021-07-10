%%file readstreamfile.m
function bitstream_d = readstreamfile(streamfile)
    fid = fopen(streamfile, 'r');
    buffer = fread(fid, 'uint8');
    fclose(fid);
    count_stream = numel(buffer);
    all_len_byte = count_stream - 1;
    padding_len = buffer(count_stream);
    stream_len = all_len_byte * 8 - padding_len;
    bitstream_array = zeros(8, count_stream);

    for BIT = 1:8
        bitstream_array(BIT, :) = bitget(buffer, 8 - BIT + 1)';
    end

    bitstream_array = bitstream_array(:);
    bitstream_d = bitstream_array(1:stream_len)';
end
