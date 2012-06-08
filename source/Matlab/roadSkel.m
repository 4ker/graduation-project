function roadSkel(readLineFile, saveSkelFile, radius, spurLen, treeFilterT)
%-------------------------------------------------------------
%����5
%��hough���������߶�ͼ���д���õ����յ�·���
%readLineFile: �����ֵ�߶�ͼ
%saveSkelFile: �������ս��ͼ
%radius : �������ʹ���ĽṹԪ��(disk)�İ뾶, Ĭ��5
%spurLen: Ҫȥ����ë�̵���󳤶ȣ� Ĭ��10
%treeFilterT: ����ͨͼ���˳�����ֵ��Ĭ��500
%-------------------------------------------------------------
if nargin < 5
    radius = 5;
end
if nargin < 4
    spurLen = 10;
end
if nargin < 3
    treeFilterT = 500;
end

if ischar(radius)
    radius = str2num(radius);
end
if ischar(spurLen)
    spurLen = str2num(spurLen);
end
if ischar(treeFilterT)
    treeFilterT = str2num(treeFilterT);
end

[header, img_Line] = getImg(readLineFile);
se = strel('disk',radius);
imdilateBW = imdilate(img_Line,se); %����
fprintf(1, '20%% Done!\n');
skelBW = bwmorph(imdilateBW,'skel',Inf); %�Ǽܻ�
spurBW = bwmorph(skelBW,'spur',spurLen);  %ȥ��ë��
fprintf(1, '50%% Done!\n');
treeFilterBW = treeFilter(spurBW, treeFilterT);
saveImg(saveSkelFile, treeFilterBW, 'ImgS', header);
fprintf(1, '100%% Done!\n');
%function end



