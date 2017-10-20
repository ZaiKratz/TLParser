#include "../Public/NearestDc.h"


//begin namespace block
namespace COMMON
{

NearestDc::NearestDc()
{
	this->_ConstructorID = -1910892683;
}

NearestDc::NearestDc(FString country, int32 this_dc, int32 nearest_dc)
{
	this->_ConstructorID = -1910892683;
	this->country = country;
	this->this_dc = this_dc;
	this->nearest_dc = nearest_dc;
}
void NearestDc::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->country);
	Writer.WriteInt(this->this_dc);
	Writer.WriteInt(this->nearest_dc);
}


void NearestDc::OnResponce(BinaryReader& Reader)
{
	country = Reader.TGReadString();
	this_dc = Reader.ReadInt();
	nearest_dc = Reader.ReadInt();
	this->_Responded = true;
}
NearestDc::~NearestDc()
{
}
}//end namespace block
