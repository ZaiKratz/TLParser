#include "../Public/KeyboardButtonRequestGeoLocation.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonRequestGeoLocation::KeyboardButtonRequestGeoLocation()
{
	this->_ConstructorID = -59151553;
}

KeyboardButtonRequestGeoLocation::KeyboardButtonRequestGeoLocation(FString text)
{
	this->_ConstructorID = -59151553;
	this->text = text;
}
void KeyboardButtonRequestGeoLocation::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
}


void KeyboardButtonRequestGeoLocation::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	this->_Responded = true;
}
KeyboardButtonRequestGeoLocation::~KeyboardButtonRequestGeoLocation()
{
}
}//end namespace block
