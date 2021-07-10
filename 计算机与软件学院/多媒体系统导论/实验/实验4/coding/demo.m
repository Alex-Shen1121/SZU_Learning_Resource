%lec4exp7
close all, clear all
%% 读入待压缩图像原始数据
filename = 'Lenna.png';
% filename = 'Weeki_Wachee_spring.jpg';
ratio = 1;
ImgLossyCodec_Encoder_Demo(filename, ratio, 1)
