//window length
int l = 0, r = 1;
int window =  r - l + 1;

//compute the area betweeen two rectangles and the distance between them
int area = min(heights[l], heights[r]) * (r - l);