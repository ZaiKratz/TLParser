#include "../Public/GetCallConfig.h"


//begin namespace block
namespace PHONE
{

GetCallConfig::GetCallConfig()
{
	this->_ConstructorID = 1430593449;
	this->_ContentRelated = true;
}
void GetCallConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetCallConfig::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::DataJSON*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetCallConfig::~GetCallConfig()
{

}
}//end namespace block
