%GETMAPPING returns a structure containing a mapping table for LBP codes.
%  MAPPING = GETMAPPING(SAMPLES,MAPPINGTYPE) returns a
%  structure containing a mapping table for
%  LBP codes in a neighbourhood of SAMPLES sampling
%  points. Possible values for MAPPINGTYPE are
%       'u2'   for uniform LBP
%       'ri'   for rotation-invariant LBP
%       'riu2' for uniform rotation-invariant LBP.
%
%  Example:
%       I=imread('rice.tif');
%       MAPPING=getmapping(16,'riu2');
%       LBPHIST=lbp(I,2,16,MAPPING,'hist');
%  Now LBPHIST contains a rotation-invariant uniform LBP
%  histogram in a (16,2) neighbourhood.
%

function mapping = getmapping(samples,mappingtype)
% Version 0.2

% Changelog
% 0.1.1 Changed output to be a structure
% Fixed a bug causing out of memory errors when generating rotation
% invariant mappings with high number of sampling points.
% Lauge Sorensen is acknowledged for spotting this problem.

% Modified by Xiaopeng HONG and Guoying ZHAO
% Changelog
% 0.2
% Solved the compatible issue for the bitshift function in Matlab
% 2012 & higher

matlab_ver = ver('MATLAB');
matlab_ver = str2double(matlab_ver.Version);

if matlab_ver < 8
    mapping = getmapping_ver7(samples,mappingtype);
else
    mapping = getmapping_ver8(samples,mappingtype);
end

end

function mapping = getmapping_ver7(samples,mappingtype)

disp('For Matlab version 7.x and lower');

table = 0:2^samples-1;
newMax  = 0; %number of patterns in the resulting LBP code
index   = 0;

if strcmp(mappingtype,'u2') %Uniform 2
    newMax = samples*(samples-1) + 3;
    for i = 0:2^samples-1
        j = bitset(bitshift(i,1,samples),1,bitget(i,samples)); %rotate left
        numt = sum(bitget(bitxor(i,j),1:samples));  %number of 1->0 and
                                                    %0->1 transitions
                                                    %in binary string
                                                    %x is equal to the
                                                    %number of 1-bits in
                                                    %XOR(x,Rotate left(x))
        if numt <= 2
            table(i+1) = index;
            index = index + 1;
        else
            table(i+1) = newMax - 1;
        end
    end
end

if strcmp(mappingtype,'ri') %Rotation invariant
    tmpMap = zeros(2^samples,1) - 1;
    for i = 0:2^samples-1
        rm = i;
        r  = i;
        
        for j = 1:samples-1
            r = bitset(bitshift(r,1,samples),1,bitget(r,samples)); %rotate
            %left
            if r < rm
                rm = r;
            end
        end
        if tmpMap(rm+1) < 0
            tmpMap(rm+1) = newMax;
            newMax = newMax + 1;
        end
        table(i+1) = tmpMap(rm+1);
    end
end

if strcmp(mappingtype,'riu2') %Uniform & Rotation invariant
    newMax = samples + 2;
    for i = 0:2^samples - 1
        j = bitset(bitshift(i,1,samples),1,bitget(i,samples)); %rotate left
        numt = sum(bitget(bitxor(i,j),1:samples));
        if numt <= 2
            table(i+1) = sum(bitget(i,1:samples));
        else
            table(i+1) = samples+1;
        end
    end
end

mapping.table=table;
mapping.samples=samples;
mapping.num=newMax;
end



function mapping = getmapping_ver8(samples,mappingtype)

disp('For Matlab version 8.0 and higher');

table = 0:2^samples-1;
newMax  = 0; %number of patterns in the resulting LBP code
index   = 0;

if strcmp(mappingtype,'u2') %Uniform 2
    newMax = samples*(samples-1) + 3;
    for i = 0:2^samples-1

        i_bin = dec2bin(i,samples);
        j_bin = circshift(i_bin',-1)';              %circularly rotate left
        numt = sum(i_bin~=j_bin);                   %number of 1->0 and
                                                    %0->1 transitions
                                                    %in binary string
                                                    %x is equal to the
                                                    %number of 1-bits in
                                                    %XOR(x,Rotate left(x))

        if numt <= 2
            table(i+1) = index;
            index = index + 1;
        else
            table(i+1) = newMax - 1;
        end
    end
end

if strcmp(mappingtype,'ri') %Rotation invariant
    tmpMap = zeros(2^samples,1) - 1;
    for i = 0:2^samples-1
        rm = i;
    
        r_bin = dec2bin(i,samples);

        for j = 1:samples-1

            r = bin2dec(circshift(r_bin',-1*j)'); %rotate left    
            if r < rm
                rm = r;
            end
        end
        if tmpMap(rm+1) < 0
            tmpMap(rm+1) = newMax;
            newMax = newMax + 1;
        end
        table(i+1) = tmpMap(rm+1);
    end
end

if strcmp(mappingtype,'riu2') %Uniform & Rotation invariant
    newMax = samples + 2;
    for i = 0:2^samples - 1
        
        i_bin =  dec2bin(i,samples);
        j_bin = circshift(i_bin',-1)';
        numt = sum(i_bin~=j_bin);
  
        if numt <= 2
            table(i+1) = sum(bitget(i,1:samples));
        else
            table(i+1) = samples+1;
        end
    end
end

mapping.table=table;
mapping.samples=samples;
mapping.num=newMax;
end
