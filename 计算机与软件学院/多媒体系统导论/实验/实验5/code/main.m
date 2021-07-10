S = load('statxture.mat');
C = load('colorMom.mat');
StatxtureData = S.Istatxture;
ColorData = C.IcolorMom;
order = zeros(1,100);

RetrieveImg = 50;    %51´ý¼ìË÷Í¼ÏñµÄ±àºÅ
for i=1:100
    order(1,i)=CalDis(ColorData(:,RetrieveImg),ColorData(:,i))*0.2+CalDis(StatxtureData(:,RetrieveImg),StatxtureData(:,i))/1000000*0.8;
end
[sA,index] = sort(order) ;

for i=2:21
    I=imread(['image\',num2str(index(i)) ,'.jpg']);
    subplot(4,5,i-1);
    imshow(I);
end
