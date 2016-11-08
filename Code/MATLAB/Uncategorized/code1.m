I=imread('test11.bmp');
bw = im2bw(I,0.999);
%se = strel('rectangle',[8 8]);
%I_1 = imopen(bw,se);
%figure, imshow(I_1);
[c,r] = imfindcircles(bw,[4,30]);
imshow(bw);viscircles(c,r);