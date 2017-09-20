#include "../Public/GetCdnConfig.h"


//begin namespace block
namespace HELP
{

GetCdnConfig::GetCdnConfig()
{
	this->_ConstructorID = 1116930642;
	this->_ContentRelated = true;
}
void GetCdnConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void GetCdnConfig::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::CdnConfig*>(Reader.TGReadObject());
}
GetCdnConfig::~GetCdnConfig()
{

}
}//end namespace block
