class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        n = len(matrix)
        m = len(matrix[0])
        first_row = 0
        last_row = n-1
        first_col =0
        last_col = m-1
        tot_ele = m*n
        ele = 0

        while(ele<tot_ele):
            #print first row
            col = first_col
            while col <= last_col and ele<tot_ele:
                ans.append(matrix[first_row][col])
                ele = ele +1
                col = col + 1

            first_row = first_row +1
            #print last col
            
            row = first_row
            while(row<=last_row and ele<tot_ele):
                ans.append(matrix[row][last_col])
                ele = ele +1
                row = row +1
                

            last_col = last_col-1

            col = last_col
            while(col >= first_col and ele<tot_ele):
                ans.append(matrix[last_row][col])
                ele = ele +1
                col = col -1

            last_row = last_row-1
            row = last_row

            while(row>=first_row and ele<tot_ele):
                ans.append(matrix[row][first_col]) 
                ele = ele +1
                row = row -1

            first_col = first_col + 1
        return ans    
       



            



            #print last col



        