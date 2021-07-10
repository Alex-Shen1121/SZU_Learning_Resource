Istatxture = zeros(256,100);
IcolorMom = zeros(225,100);

for i=1:100
    clear temp_image;
    clear s;
    s = ['image\',num2str(i) ,'.jpg'];
    temp_image = imread(s);
    Istatxture(:,i)=lbp(temp_image);
    IcolorMom(:,i)=colorMom(temp_image);
    %i
end
save statxture Istatxture;
save colorMom IcolorMom;



