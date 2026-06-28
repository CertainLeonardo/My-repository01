void decompressFile(const std::string& inputPath, const std::string& outputPath) {
    std::ifstream inFile(inputPath, std::ios::binary);
    std::ofstream outFile(outputPath, std::ios::binary);

    if (!inFile || !outFile) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    char countByte;
    char dataByte;

    // Read pairs: first the count, then the actual data byte
    while (inFile.get(countByte) && inFile.get(dataByte)) {
        unsigned char count = static_cast<unsigned char>(countByte);
        
        // Duplicate the byte back to its original form
        for (int i = 0; i < count; i++) {
            outFile.put(dataByte);
        }
    }

    inFile.close();
    outFile.close();
    std::cout << "Decompression complete!" << std::endl;
}
