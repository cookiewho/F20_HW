package table;

/**
 * A bitmap, implemented as a byte array.
 * 
 * Note that java bytes are signed, so values range
 * from -128 to 127.  A byte of all 1's is -0x01.
 * 
 * Note also that Byte.SIZE gives the number of bits in a byte.
 *
 */

public class Bitmap {
	private byte[] bytes;
	private int numBytes;
	
	/**
	 * Create a new bitmap.  The numBytes argument is provided
	 * because some applications may not want to use the entire
	 * byte array for the bitmap.
	 * @param bytes
	 * @param numBytes
	 */
	public Bitmap(byte[] bytes, int numBytes) {
		this.bytes = bytes;
		this.numBytes = numBytes;
	}
	
	/**
	 * An alternative constructor when all bits in the byte array are to be used.
	 * @param bytes
	 */
	public Bitmap(byte[] bytes) {
		this(bytes, bytes.length);
	}
	
	/**
	 * Return the number of bits in this bitmap. 
	 * @return
	 */
	public int size() { return numBytes * Byte.SIZE; }
	
	/**
	 * Set all bits in the bitmap to 0.
	 */
	public void clear() {
		for (int i = 0; i < numBytes; i++) {
			bytes[i] = 0;
		}
	}
	
	/**
	 * Return true if the ith bit is 1, else return false.
	 * @param i
	 * @return
	 */
	public boolean getBit(int i) {
		int ind = i/8;
		byte a = bytes[ind];
		int shift = 7-(i%8);
		byte masksk = (byte) (1 << shift);
		return (a & masksk)!=0;
	}
	
	/**
	 * Set the ith bit to 1 (if bit is true) or 0 (if not)
	 * @param i
	 * @param bit
	 */
	public void setBit(int i, boolean bit) {
		int ind = i/8;
		byte a = bytes[ind];
		int shift = 7-(i%8);
		byte masksk = (byte) (1 << shift);
		if(bit == true){
			a = (byte) (a | masksk);
		}else {
			a = (byte) (a & ~masksk);
		}
		bytes[ind] = a;
	}
	
	// return true if the ith bit of b is 1, else return false
	private boolean getBit(byte b, int i) {
		int shift = 7-(i%8);
		byte masksk = (byte) (1 << shift);
		System.out.println(masksk);
		return (b & masksk)==1;
	}
	
	// return a byte like b except with bit i set to 1 (if bit is true) or 0 (if not)
	private byte setBit(byte b, int i, boolean bit) {
		System.out.println("curr value: " + Byte.toString(b));
		int shift = 7-(i%8);
		byte masksk = (byte) (1 << shift);
		if(bit == true){
			b = (byte) (b | masksk);
		}else {
			b = (byte) (b & ~masksk);
		}
		System.out.println("curr value: " + Byte.toString(b));
		return b;
	}
		
	/** 
	 * Return the bitmap as a string
	 */
	public String toString() {
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < size(); i++) {
			if (i > 0 && i % Byte.SIZE == 0) {
				sb.append(" ");
			}
			sb.append(getBit(i) ? "1" : "0");
		}
		return sb.toString();
	}
}
