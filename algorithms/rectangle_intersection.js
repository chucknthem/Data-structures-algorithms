/*
 * Return the intersecting rectangle of two rectangles on a cartesian plane.
 * Rectangles R1 has bottom left and top right coordinates (x1, y1) and (x2, y2) respectively.
 * Rectangles R2 has bottom left and top right coordinates (x3, y3) and (x4, y4) respectively.
 *
 * returns a rectangle object if the rectangle intersects or null if they don't.
 *
 * DETAILS:
 * Suppose we have two rectangles R1 and R2. Let (x1, y1) be the location of the bottom-left corner of R1 and (x2, y2) be the location of its top-right corner. Similarly, let (x3, y3) and (x4, y4) be the respective corner locations for R2. The intersection of R1 and R2 will be a rectangle R3 whose bottom-left corner is at (max(x1, x3), max(y1, y3)) and top-right corner at (min(x2, x4), min(y2, y4)). If max(x1, x3) > min(x2, x4) or max(y1, y3) > min(y2, y4) then R3 does not exist, ie R1 and R2 do not intersect. This method can be extended to intersection in more than 2 dimensions as seen in CuboidJoin (SRM 191, Div 2 Hard). 
 */
function rectIntersect(x1, y1, x2, y2, x3, y3, x4, y4) {
  var rect = {
    x1: Math.max(x1, x3),
    y1: Math.max(y1, y3),
    x2: Math.min(x2, x4),
    y2: Math.min(y2, y4) 
  }
  if (rect.x1 > rect.x2 || rect.y1 > rect.y2) 
    return null;

  return rect;

}
