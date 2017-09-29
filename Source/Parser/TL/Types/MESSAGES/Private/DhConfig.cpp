#include "../Public/DhConfig.h"


//begin namespace block
namespace MESSAGES
{

DhConfig::DhConfig()
{
	this->_ConstructorID = 740433629;
}

DhConfig::DhConfig(int32 g, TArray<uint8>  p, int32 version, TArray<uint8>  random)
{
	this->_ConstructorID = 740433629;
	this->g = g;
	this->p = p;
	this->version = version;
	this->random = random;
}
void DhConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->g);
	Writer.TGWriteBytes((unsigned char*)this->p.GetData(), this->p.Num());
	Writer.WriteInt(this->version);
	Writer.TGWriteBytes((unsigned char*)this->random.GetData(), this->random.Num());
}


void DhConfig::OnResponce(BinaryReader& Reader)
{
	g = Reader.ReadInt();
	p = Reader.TGReadBytes();
	version = Reader.ReadInt();
	random = Reader.TGReadBytes();
	this->_Responded = true;
}
DhConfig::~DhConfig()
{

}
}//end namespace block
