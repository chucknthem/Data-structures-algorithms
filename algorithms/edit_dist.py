# The edit distance or Levenshteien distance between two strings is the 
# minimum number of insertion, deletion, and substitution operations it takes
# to transfer one string into another.
# http://en.wikipedia.org/wiki/Levenshtein_distance

# This algorithm uses a bottom up dynamic programming approach to calculate
# the edit distance. Using a 2D array d of size [m + 1][n + 1] where m and n
# are the length of strings a and b respectively. d[i][j] represents the 
# edit distance of the substrings a[0:i] and b[0:j]
def edit_dist(str1, str2):
  w = len(str1) + 1
  h = len(str2) + 1
  d = [[0 for i in xrange(w)] for j in xrange(h)]
  # The edit distance of str1 and the empty string is i.
  for i in xrange(w):
    d[0][i] = i
  # The edit distance of str2 and the empty string is j.
  for j in xrange(h):
    d[j][0] = j

  for j in xrange(1, h):
    for i in xrange(1, w):
      if str1[i - 1] == str2[j - 1]:
        d[j][i] = d[j - 1][i - 1] # No change.
      else:
        d[j][i] = min(
            d[j - 1][i] + 1, # Deletion
            d[j][i - 1] + 1, # Insertion
            d[j - 1][i - 1] + 1 # Substitution
            )
  return d[len(str2)][len(str1)]

if __name__ == '__main__':
  print edit_dist('medic', 'edit')

