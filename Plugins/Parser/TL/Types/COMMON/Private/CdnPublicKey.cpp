#include "../Public/CdnPublicKey.h"


//begin namespace block
namespace COMMON
{

CdnPublicKey::CdnPublicKey()
{
	this->_ConstructorID = -1159036215;
}

CdnPublicKey::CdnPublicKey(int32 dc_id, FString public_key)
{
	this->_ConstructorID = -1159036215;
	this->dc_id = dc_id;
	this->public_key = public_key;
}
void CdnPublicKey::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->dc_id);
	Writer.TGWriteString(this->public_key);
}


void CdnPublicKey::OnResponce(BinaryReader& Reader)
{
	dc_id = Reader.ReadInt();
	public_key = Reader.TGReadString();
}
CdnPublicKey::~CdnPublicKey()
{

}
}//end namespace block
