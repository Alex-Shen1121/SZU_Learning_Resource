function [ Dis ] = CalDis( arg1,arg2 )
%UNTITLED5 Summary of this function goes here
%   Detailed explanation goes here
    X = [arg1' ; arg2'];
    Dis = pdist(X,'euclidean');
end

