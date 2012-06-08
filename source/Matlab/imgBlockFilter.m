function img_ans = imgBlockFilter(image, winSize, thresh)
%-------------------------------------------------------------
%���ݶ�ֵͼ������ڵ�("1")����Ŀ���������������
%image: �����ֵͼ����
%winSize: �����ߴ�
%thresh: �ж���ֵ
%img_ans: �����Ķ�ֵͼ����
%-------------------------------------------------------------
[width, height] = size(image);
img_ans = image;
radius = floor(winSize/2);
for i = radius+1 : width-radius
    for j = radius+1 : height-radius
        count = sum(sum(image(i-radius:i+radius,j-radius:j+radius),1),2);
        if count >= winSize*winSize-thresh
            img_ans(i,j) = 1; %���
        elseif count < thresh
            img_ans(i,j) = 0; %���
        end
    end
    fprintf(1, '%d%%\n', int32(i/(width-radius)*60));
end
%function end