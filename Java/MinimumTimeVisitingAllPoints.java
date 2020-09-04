class Point {
     public int x; 
     public int y; 
     public boolean init;
    
     public Point() {
         init = false;
     }
    
     public Point(int x, int y) {
         this.x = x;
         this.y = y;
         init = true;
     }
}

class Solution {
    
    public int getLongestDistance(Point p1, Point p2) {
        int diffX = Math.abs(p1.x - p2.x); 
        int diffY = Math.abs(p1.y - p2.y);
        
        return (diffX > diffY)? diffX: diffY;
    }
    
    public int minTimeToVisitAllPoints(int[][] points) {
        Point previousPoint = new Point();
        int seconds = 0;
        for (int row = 0; row < points.length; row++) { 
            Point currentPoint = new Point(points[row][0], points[row][1]);
            
            if(previousPoint.init) 
                seconds += getLongestDistance(previousPoint, currentPoint);
            
            previousPoint = currentPoint;
        }
        
        return seconds;
    }
}