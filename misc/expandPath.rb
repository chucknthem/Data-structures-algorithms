#/usr/bin/env ruby
# Demonstrates a simple stack based algorithm for expanding a Path to a full
# Path . e.g. http://www.example.com/./foo/../bar/a/../b/c will expand to 
# http://www.example.com/bar/b/c

# Return the full path given a composite path
def expandPath(url)
  stack = []
  urlTokens = url.split '/'
  while urlTokens.count > 0
    token = urlTokens.shift
    next if token == '.'
    if token == '..'
      puts 'error: invalid path' and return if stack.count == 0
      stack.pop
    else
      stack.push token
    end
  end
  stack.join('/')
end
def usage
  "Usage: ruby #{$0}
  http://google.com/xyz/../abc/
  >http://google.com/abc"
end
puts usage
ARGF.each do |line| 
  puts expandPath line.chomp!
end
