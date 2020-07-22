char* vgaBuffer = (char*) 0xb8000; // screen buffer

#define VGA_HEIGHT 80 // screen height
#define VGA_WIDTH 25 // screen width

// We will come to this later
void terminal_clear_screen(void);

kernel_main()
{
	terminal_clear_screen();
	
	/*
	Each VGA character is 16 bits. First 8 bits determine the ASCII character
	and last 8 bits determine the color of that character. We used an 
	8 bit char pointer for avoiding compelixy when writing to VGA character 
	slots. There for each 2 indexes are a single VGA slot here.
	*/	 

	vgaBuffer[0]  = 'H'; // First 8 bits: character
	vgaBuffer[1]  =  79; // Last  8 bits: color

	vgaBuffer[2]  = 'e'; // First 8 bits: character
	vgaBuffer[3]  =  15; // Last  8 bits: color

	vgaBuffer[4]  = 'l'; // and so on...
	vgaBuffer[5]  =  10; 

	vgaBuffer[6]  = 'l'; 
	vgaBuffer[7]  =   4; 

	vgaBuffer[8]  = 'o'; 
	vgaBuffer[9]  = 160; 

	vgaBuffer[10] = '!';
	vgaBuffer[11] =  64;

	// Printing text in a practical way complicates the code a fair bit 
	// so I have deleted those parts
}

// We have to clear the left over text from boot screen
void terminal_clear_screen(void)
{
	/*
	We multiply width by 2 because we have an 8 bit pointer instead of a 
	16 bit. Therefore we have to increment twice on horizontal axis in 
	order to reach to the next VGA character
	*/	
	int limit = (VGA_WIDTH * 2) * (VGA_HEIGHT); 
	for (int i = 0; i < limit; ++i) {
		vgaBuffer[i] = 0;
	}
}