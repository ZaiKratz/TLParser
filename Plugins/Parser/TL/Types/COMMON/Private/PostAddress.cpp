#include "../Public/PostAddress.h"


//begin namespace block
namespace COMMON
{

PostAddress::PostAddress()
{
	this->_ConstructorID = -341144546;
}

PostAddress::PostAddress(FString street_line1, FString street_line2, FString city, FString state, FString country_iso2, FString post_code)
{
	this->_ConstructorID = -341144546;
	this->street_line1 = street_line1;
	this->street_line2 = street_line2;
	this->city = city;
	this->state = state;
	this->country_iso2 = country_iso2;
	this->post_code = post_code;
}
void PostAddress::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->street_line1);
	Writer.TGWriteString(this->street_line2);
	Writer.TGWriteString(this->city);
	Writer.TGWriteString(this->state);
	Writer.TGWriteString(this->country_iso2);
	Writer.TGWriteString(this->post_code);
}


void PostAddress::OnResponce(BinaryReader& Reader)
{
	street_line1 = Reader.TGReadString();
	street_line2 = Reader.TGReadString();
	city = Reader.TGReadString();
	state = Reader.TGReadString();
	country_iso2 = Reader.TGReadString();
	post_code = Reader.TGReadString();
}
PostAddress::~PostAddress()
{

}
}//end namespace block
