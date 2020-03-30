#include "_helper.h"

/** Flood Fill | Leetcode Easy
 * https://leetcode.com/problems/flood-fill/
 * An image is represented by a 2-D array of integers, each integer representing
 * the pixel value of the image (from 0 to 65535).
 *
 * Given a coordinate (sr, sc) representing the starting pixel (row and column)
 * of the flood fill, and a pixel value newColor, "flood fill" the image.
 *
 * To perform a "flood fill", consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color as the starting pixel), and so on.
 * Replace the color of all of the aforementioned pixels with the newColor.
 *
 * At the end, return the modified image.
 * Example 1:
 * Input:
 * image = [[1,1,1],
 *          [1,1,0],
 *          [1,0,1]]
 * sr = 1, sc = 1, newColor = 2
 * Output: [[2,2,2],
 *          [2,2,0],
 *          [2,0,1]]
 * Explanation:
 *
 * From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected
 * by a path of the same color as the starting pixel are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally connected
 * to the starting pixel.
 *
 * Note:
 * 1. The length of image and image[0] will be in the range [1, 50].
 * 2. The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
 * 3. The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
 */

void DFS(vector<vector<int>>& image, int r, int c, int paint_color, int newColor){
    int R = image.size();
    int C = image[0].size();

    image[r][c] = newColor;

    if(r>=1 && image[r-1][c] == paint_color){
        DFS(image, r-1, c, paint_color, newColor);
    }

    if(r+1<R && image[r+1][c] == paint_color){
        DFS(image, r+1, c, paint_color, newColor);
    }

    if(c>=1 && image[r][c-1] == paint_color){
        DFS(image, r, c-1, paint_color, newColor);
    }

    if(c+1<C && image[r][c+1] == paint_color){
        DFS(image, r, c+1, paint_color, newColor);
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int R = image.size();
    int C = image[0].size();

    int paint_color = image[sr][sc];

    if(paint_color != newColor)
        DFS(image, sr, sc, paint_color, newColor);

    return image;
}



// USing DFS
void DFS2(vector<vector<int>>& image, int r, int c, int oldColor, int newColor){
    int R = image.size();
    int C = image[0].size();
    
    if(r<0 || r>= R || c<0 || c>= C || image[r][c] != oldColor){
        return;
    }
    
    if(image[r][c] == oldColor)
        image[r][c] = newColor;
    
    DFS2(image, r+1, c, oldColor, newColor);
    DFS2(image, r-1, c, oldColor, newColor);
    DFS2(image, r, c+1, oldColor, newColor);
    DFS2(image, r, c-1, oldColor, newColor);
    
}

vector<vector<int>> floodFill2(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int R = image.size();
    int C = image[0].size();
    
    int oldColor = image[sr][sc];
    
    if(oldColor != newColor)
        DFS2(image, sr, sc, oldColor, newColor);
    
    return image;        
}
