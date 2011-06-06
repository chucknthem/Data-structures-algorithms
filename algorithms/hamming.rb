# Calculate the hamming distance between two numbers.
def hamming(n1, n2)
  h, d = 0, n1^n2
  while d != 0
    h += 1
    d &= d - 1
  end
  return h
end

def main
  print hamming(0b1101110011011, 0b1101110110011) # 2
end
if __FILE__ == $0
  main
end
