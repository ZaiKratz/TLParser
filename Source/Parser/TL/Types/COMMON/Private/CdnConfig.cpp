#include "../Public/CdnConfig.h"


//begin namespace block
namespace COMMON
{

CdnConfig::CdnConfig()
{
	this->_ConstructorID = 1462101002;
}

CdnConfig::CdnConfig(TArray<COMMON::CdnPublicKey*>  public_keys)
{
	this->_ConstructorID = 1462101002;
	this->public_keys = public_keys;
}
void CdnConfig::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->public_keys.Num());
	for(auto X : this->public_keys)
	{
	X->OnSend(Writer);
	}
}


void CdnConfig::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len19985 = Reader.ReadInt();
	for(int32 i = 0; i < Len19985; i++)
	{
	auto X = reinterpret_cast<COMMON::CdnPublicKey*>(Reader.TGReadObject());
	public_keys.Add(X);
	}
	this->_Responded = true;
}
CdnConfig::~CdnConfig()
{

}
}//end namespace block
