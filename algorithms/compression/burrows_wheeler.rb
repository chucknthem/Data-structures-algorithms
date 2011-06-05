# http://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform
# A technique that transforms text into a more compressable format.
#
# transform:
# 0. Prepend and append a start and end symbol to the string. e.g.
#    "charles" -> "^charles$"
# 1. Build a table using the input string where each successive row is the
#    next rotation in the string.
#    e.g. "charles" -> ["charles", "scharle", "escharl", ...]
# 2. Sort the table by the first column.
# 3. The last column of this table is the output of the transformation.
def transform(str)
  str = "^#{str}$"
  table = [str.dup]
  len = str.length
  (1...len).each do
    c = str.slice!(len - 1)
    str = c + str

    table << str.dup
  end

  table.sort!
  newstr = ""
  (0...len).each do |i|
    s = table[i]
    newstr << "#{s[len -1]}"
  end
  return newstr
end

# Reverse:
# given str as input:
# 1. Create an empty table.
# 2. loop str.length times:
#    a. Insert str as the first column of the table.
#    b. Sort the table rows by column.
def reverse(str)
  table = str.split //
  table.sort!
  len = str.length
  (1...len).each do |i|
    (0...len).each do |j|
      table[j] = str[j] << table[j]
    end
    table.sort!
  end
  table.each do |row|
      return row if row[len - 1] == "$"
  end
  return ""
end

m = "hello my name is charles what's your name?"
t = transform(m)
r = reverse(t)
print "^#{m}$\n#{t}\n#{r}\n"
if "^#{m}$" === r
  print "Win!\n"
else
  print "Fail.\n"
end
