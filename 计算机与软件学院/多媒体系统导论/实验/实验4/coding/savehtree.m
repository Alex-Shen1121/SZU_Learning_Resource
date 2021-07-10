%%file savehtree.m
function size_dict = savehtree(htreefile, dict)
    tb = fopen(htreefile, 'w');
    size_dict = 0;

    for i = 1:size(dict, 1)
        size_dict = size_dict + fprintf(tb, '%s', num2str(dict{i, 1}));
        size_dict = size_dict + fprintf(tb, '%c', ' ');
        size_dict = size_dict + fprintf(tb, '%s', string(dict{i, 2}));

        if i < size(dict, 1)
            size_dict = size_dict + fprintf(tb, '%c', ' ');
        end

    end

    fclose(tb);
end
