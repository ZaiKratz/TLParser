#include "../Public/GetDhConfig.h"


//begin namespace block
namespace MESSAGES
{

GetDhConfig::GetDhConfig()
{
	this->_ConstructorID = 1351208742;
	this->_ContentRelated = true;
}

GetDhConfig::GetDhConfig(int32 version, int32 random_length)
{
	this->_ConstructorID = 1351208742;
	this->_ContentRelated = true;
	this->version = version;
	this->random_length = random_length;
}
void GetDhConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->version);
	Writer.WriteInt(this->random_length);
}


void GetDhConfig::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<MESSAGES::DhConfig*>(Reader.TGReadObject());
}
GetDhConfig::~GetDhConfig()
{

}
}//end namespace block
