class BruteForceSolution:
    def maxArea(self, height) -> int:
        currentMaxArea = 0
        for i, value in enumerate(height):
            for j, value in enumerate(height):
                maxJ = 0
                if j > maxJ and j > i:
                    maxJ = j
                    trueHeight = min(height[i],height[j])
                    width = j - i
                    area = trueHeight * width
                    if area > currentMaxArea:
                        currentMaxArea = area
        return currentMaxArea
    
    
class WorkingSolution:
    def MaxArea(self, height) -> int:
        
        maxAreaResult = 0
        
        l, r = 0, len(height) - 1
        while (l < r):
            area = l * (r-l)
            maxAreaResult = max(maxAreaResult, area)
            if height[l] < height[r]:
                l += 1
            elif height[l] > height[r]:
                r += 1
            else:
                l += 1
            
                
            
            
            