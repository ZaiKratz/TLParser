#include "../Public/GetConfig.h"


//begin namespace block
namespace HELP
{

GetConfig::GetConfig()
{
	this->_ConstructorID = -990308245;
	this->_ContentRelated = true;
}
void GetConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetConfig::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Config*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetConfig::~GetConfig()
{

}
}//end namespace block
