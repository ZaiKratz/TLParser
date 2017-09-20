#include "../Public/GetNearestDc.h"


//begin namespace block
namespace HELP
{

GetNearestDc::GetNearestDc()
{
	this->_ConstructorID = 640725791;
	this->_ContentRelated = true;
}
void GetNearestDc::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetNearestDc::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::NearestDc*>(Reader.TGReadObject());
}
GetNearestDc::~GetNearestDc()
{

}
}//end namespace block
