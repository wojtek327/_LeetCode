int countSeniors(char ** details, int detailsSize){
    int numberOfPeopleOver60 = 0;
    int convertedValue = 0;
    for(uint8_t i=0; i<detailsSize; i++) {
        convertedValue = ((details[i][11] - 0x30) * 10) + (details[i][12] - 0x30);
        if(convertedValue > 60) {
            numberOfPeopleOver60++;
        }
    }
    return numberOfPeopleOver60;
}
//---------------------------------------------------------------------------------------
