require 'rmagick'
include Magick

def avphash(imgfile)
  """Average perception hash algorithm.

  1. Convert image to grayscale.
  2. Reduce image size to 8x8 (or 64 pixels).
  3. Calculate the average.
  4. Set the bits in the hash such that it's 1 if the pixel is greater than the
     average and 0 if the pixel is <= the average.
  """

  img = ImageList.new(imgfile)
  .quantize(256, Magick::GRAYColorspace)
  .resize!(8, 8)
  .set_channel_depth(Magick::AllChannels, 8)
  .quantize(256, Magick::GRAYColorspace)

  pixels = img.get_pixels(0, 0, 8, 8)

  avg = pixels.reduce(0) { |s, p| s += p.red } /pixels.length
  i = 0 
  h = pixels.reduce(0) do |h, p| 
    h |= (1 << i) if (p.red > avg)
    i += 1
    h
  end
  return h
end

def main
  print avphash(ARGV[0]) 
end

if __FILE__ == $0
  main
end
