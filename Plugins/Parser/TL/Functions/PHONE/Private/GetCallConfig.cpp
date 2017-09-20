#include "../Public/GetCallConfig.h"


//begin namespace block
namespace PHONE
{

GetCallConfig::GetCallConfig()
{
	this->_ConstructorID = -1457568427;
	this->_ContentRelated = true;
}
void GetCallConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetCallConfig::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::DataJSON*>(Reader.TGReadObject());
}
GetCallConfig::~GetCallConfig()
{

}
}//end namespace block
