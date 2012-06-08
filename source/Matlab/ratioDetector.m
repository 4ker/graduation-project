function [img_edge, img_Direction] = ratioDetector(img_data, ...
    winSize, thresh)
%-------------------------------------------------------------
%Ratio���ӱ�Ե���
%img_data: ����ͼ�����(0-255�Ҷ�ͼ),
%winSize:  ��ⴰ�ڴ�С,Ĭ��5
%thresh:   �ָ���ֵ(r < thresh ���϶��õ����ڱ�Ե��)��Ĭ��0.3
%img_edge: ��Ե��ȡ��Ķ�ֵͼ����
%img_Direction: ��Ӧimg_edge�ķ���ֵ"��ֱ":1 "ˮƽ":2 "����\":3 "����/":4
%-------------------------------------------------------------
if nargin < 3 
    thresh = 0.3; 
end
if nargin < 2 
    winSize = 5;
end

radius = floor(winSize/2); %���ڰ뾶
img_data = double(img_data); %ת��double���ں�����ͼ���
[width, height] = size(img_data);
img_edge = zeros(width, height);
img_Direction = zeros(width, height);

for i = radius+1 : width-radius
    for j = radius+1 : height-radius
        %��ֱ����
        u1 = sum(sum(img_data(i-radius:i-1,j-radius:j+radius),1),2);
        u2 = sum(sum(img_data(i+1:i+radius,j-radius:j+radius),1),2);
        r1 = double(min(u1,u2))/max(u1,u2);
        %ˮƽ����
        u1 = sum(sum(img_data(i-radius:i+radius,j-radius:j-1),1),2);
        u2 = sum(sum(img_data(i-radius:i+radius,j+1:j+radius),1),2);
        r2 = double(min(u1,u2))/max(u1,u2);
        %����45��"\"
        u1 = 0;
        u2 = 0;
        for m = 0 : winSize-1
            for n = 0 : winSize-1
                if m > n
                    u1 = u1 + img_data(i-radius+m, j-radius+n);
                elseif m < n
                    u2 = u2 + img_data(i-radius+m, j-radius+n);
                end
            end
        end
        r3 = double(min(u1,u2))/max(u1,u2);
        %����45��"/"
        u1 = 0;
        u2 = 0;
        for m = 0 : winSize-1
            for n = 0 : winSize-1
                if m > (winSize-1-n)
                    u1 = u1 + img_data(i-radius+m, j-radius+n);
                elseif m < (winSize-1-n)
                    u2 = u2 + img_data(i-radius+m, j-radius+n);
                end
            end
        end
        r4 = double(min(u1,u2))/max(u1,u2);
        
        %4������ȡ��Сֵ
        [r index] = min([r1,r2,r3,r4]);
        if r < thresh
            img_Direction(i, j) = index;
            img_edge(i, j) = 1;     
        end
    end
    fprintf(1, '%d%%\n', int32(i/(width-radius)*96));
end
%fucntion end