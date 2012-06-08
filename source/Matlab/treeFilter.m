function imgAns = treeFilter(img_Skel, thresh)
%-------------------------------------------------------------
%������ֵȥ������ͼ�еĲ�����
%img_Skel: �����·��״����ͼ
%thresh: ����С��ֵ
%imgAns: ������ͼ
%-------------------------------------------------------------
set(0,'RecursionLimit',2000);

img = img_Skel;
[width, height] = size(img);
global imgTree;  %ȫ�ֱ���
imgAns = zeros(width, height);

while sum(sum(img,1),2) > 0
    flag = 0;
    imgTree = zeros(width, height);
    for i = 1:width
        for j = 1:height
            if 1 == img(i, j)
                flag = 1;
                break;
            end
        end
        if 1 == flag
            break;
        end
    end
    markLine(img, 1, [i, j]);
    if sum(sum(imgTree,1),2) > thresh
        imgAns = imgAns + imgTree;
    end
    img = img - imgTree;
end

%function end