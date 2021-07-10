%%file readhtree.m
function dict_d = readhtree(htreefile)
    fid = fopen(htreefile, 'r');
    tmpd = fscanf(fid, '%c');
    fclose(fid);
    tmp = split(tmpd);

    for i = 1:size(tmp) / 2
        dict_d{i, 1} = str2num(tmp{i * 2 - 1});
        tmp_array = [];

        for j = 1:size(tmp{i * 2}, 2)
            tmp_array = [tmp_array str2double(tmp{i * 2}(j))];
        end

        dict_d{i, 2} = tmp_array;
    end

end
