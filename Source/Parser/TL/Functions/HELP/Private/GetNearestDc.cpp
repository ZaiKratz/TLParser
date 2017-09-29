#include "../Public/GetNearestDc.h"


//begin namespace block
namespace HELP
{

GetNearestDc::GetNearestDc()
{
	this->_ConstructorID = 531836966;
	this->_ContentRelated = true;
}
void GetNearestDc::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetNearestDc::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::NearestDc*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetNearestDc::~GetNearestDc()
{

}
}//end namespace block
