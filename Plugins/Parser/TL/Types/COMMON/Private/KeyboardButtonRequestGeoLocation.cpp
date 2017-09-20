#include "../Public/KeyboardButtonRequestGeoLocation.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonRequestGeoLocation::KeyboardButtonRequestGeoLocation()
{
	this->_ConstructorID = 1064008188;
}

KeyboardButtonRequestGeoLocation::KeyboardButtonRequestGeoLocation(FString text)
{
	this->_ConstructorID = 1064008188;
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
}
KeyboardButtonRequestGeoLocation::~KeyboardButtonRequestGeoLocation()
{

}
}//end namespace block
