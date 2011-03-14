#/usr/bin/env ruby
# Demonstrates a simple stack based algorithm for expanding a URL to a full
# URL. e.g. http://www.example.com/./foo/../bar/a/../b/c will expand to 
# http://www.example.com/bar/b/c

# Return the full url given a composite URL
def fullUrl(url)
  stack = []
  urlTokens = url.split '/'
  while urlTokens.count > 0
    token = urlTokens.shift
    next if token == '.'
    if token == '..'
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
  puts fullUrl line.chomp!
end
