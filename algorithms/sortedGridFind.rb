#/usr/bin/ruby
# Given a 2d grid of numbers sorted on rows and columns
# check if an element i is in the grid
# worse case run time O(sqrt(n)), it's optimal for this problem
#
# the grid is sorted left->right, bottom->top in ascending order
require 'pp'
def gridFind(grid, i)
  r = grid.count - 1
  c = grid[0].count - 1
  while r >= 0 and c >= 0
    if grid[r][c] > i
      c -= 1
    elsif grid[r][c] < i
      r -= 1
    else
      return true
    end
  end
  return false
end

grid = [
  [70, 72, 85, 87, 98, 99], 
  [35, 57, 67, 78, 88, 89], 
  [23, 45, 64, 67, 70, 80],
  [13, 23, 25, 47, 56, 72],
  [ 9, 10, 15, 20, 30, 40],
  [ 1,  2,  3,  4,  5,  6]]

puts gridFind(grid, ARGV[0].to_i)

