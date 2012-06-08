function imgAns = treeFilter(img_Skel, thresh)
%-------------------------------------------------------------
%根据阈值去除线条图中的部分树
%img_Skel: 输入道路网状线条图
%thresh: 树大小阈值
%imgAns: 输出结果图
%-------------------------------------------------------------
set(0,'RecursionLimit',2000);

img = img_Skel;
[width, height] = size(img);
global imgTree;  %全局变量
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