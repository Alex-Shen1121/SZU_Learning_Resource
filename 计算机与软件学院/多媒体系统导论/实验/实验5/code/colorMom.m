function cmVec = colorMom(jpgfile)
% function cmVec = colorMom(direc)
% Input: directory of a JPG image
% Output: a color moment feature vector of the input image. The feature
% vector is extracted from a 5*5 grid and represented by the first 3
% moments for each grid region in Lab color space as a normalized
% 225-dimensional vector.
% Function RGB2Lab (By Mr. Ruzon in Stanford U.) is used in this function.

%jpgfile = imread(direc);
% jpgfile = imread('shot141_18_NRKF_1.jpg');
if length(size(jpgfile))==2
    jpgfile1=zeros(size(jpgfile,1),size(jpgfile,2),3);
    jpgfile1(:,:,1)=jpgfile;
    jpgfile1(:,:,2)=jpgfile;
    jpgfile1(:,:,3)=jpgfile;    
    jpgfile=jpgfile1;
end

% labfile = RGB2Lab(jpgfile);
[a b c] = size(jpgfile);
% m, n represent sizes of the grid
m = floor(a/5);
n = floor(b/5);
cmVec = zeros(1,225);% 5x5 x9,9¸öÌØÕ÷
for i=1:5
    for j = 1:5
%        subimage = labfile((i-1)*m+1:i*m,(j-1)*n+1:j*n,:);
         subimage = jpgfile((i-1)*m+1:i*m,(j-1)*n+1:j*n,:);
% cal. Mean, ...
        tmp = (i-1)*5+j-1;
%         I=imshow(subimage,[]);
        cmVec(tmp*9+1) = mean(mean(subimage(:,:,1)));
        cmVec(tmp*9+2) = mean(mean(subimage(:,:,2)));
        cmVec(tmp*9+3) = mean(mean(subimage(:,:,3)));
        % cal Moment 2 and 3
        for p = 1:m
            for q = 1:n
                % === Moment2
                cmVec(tmp*9+4) = cmVec(tmp*9+4) + (subimage(p,q,1)-cmVec(tmp*9+1))^2;
                cmVec(tmp*9+5) = cmVec(tmp*9+5) + (subimage(p,q,2)-cmVec(tmp*9+2))^2;
                cmVec(tmp*9+6) = cmVec(tmp*9+6) + (subimage(p,q,3)-cmVec(tmp*9+3))^2;
                % === Moment3
                cmVec(tmp*9+7) = cmVec(tmp*9+7) + (subimage(p,q,1)-cmVec(tmp*9+1))^3;
                cmVec(tmp*9+8) = cmVec(tmp*9+8) + (subimage(p,q,2)-cmVec(tmp*9+2))^3;
                cmVec(tmp*9+9) = cmVec(tmp*9+9) + (subimage(p,q,3)-cmVec(tmp*9+3))^3;                
            end
        end
        cmVec((tmp*9+4):(tmp*9+9)) = cmVec((tmp*9+4):(tmp*9+9))/(m*n);
        cmVec(tmp*9+4) = cmVec(tmp*9+4)^(1/2);
        cmVec(tmp*9+5) = cmVec(tmp*9+5)^(1/2);
        cmVec(tmp*9+6) = cmVec(tmp*9+6)^(1/2);

        if cmVec(tmp*9+7) >0
            cmVec(tmp*9+7) = cmVec(tmp*9+7)^(1/3);
        else
            cmVec(tmp*9+7) = -((-cmVec(tmp*9+7))^(1/3));
        end
        if cmVec(tmp*9+8) >0
            cmVec(tmp*9+8) = cmVec(tmp*9+8)^(1/3);
        else
            cmVec(tmp*9+8) = -((-cmVec(tmp*9+8))^(1/3));
        end
        if cmVec(tmp*9+9) >0
            cmVec(tmp*9+9) = cmVec(tmp*9+9)^(1/3);
        else
            cmVec(tmp*9+9) = -((-cmVec(tmp*9+9))^(1/3));
        end 
        
    end
end
% Normalize...
if sqrt(sum(cmVec.^2))~=0
    cmVec = cmVec / sqrt(sum(cmVec.^2));
end