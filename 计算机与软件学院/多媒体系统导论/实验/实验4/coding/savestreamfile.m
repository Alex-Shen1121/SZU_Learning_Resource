%%file savestreamfile.m
function count_stream = savestreamfile(streamfile, bitstream)
    count_stream = 0;
    stream_len = numel(bitstream);
    padding_len = 8 - mod(stream_len, 8);
    all_len = stream_len + padding_len;
    bitstream_temp = zeros(all_len, 1);
    bitstream_temp(1:stream_len) = bitstream;
    bitstream_array = reshape(bitstream_temp, 8, floor(all_len / 8));
    buffer = uint8(zeros(floor(all_len / 8), 1));

    for BIT = 1:8
        buffer = bitset(buffer, 8 - BIT + 1, bitstream_array(BIT, :)');
    end

    tstream = fopen(streamfile, 'w');
    count_stream = fwrite(tstream, buffer, 'uint8');
    count_stream = count_stream + fwrite(tstream, padding_len, 'uint8');
    fclose(tstream);
end
