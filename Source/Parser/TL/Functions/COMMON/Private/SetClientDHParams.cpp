#include "../Public/SetClientDHParams.h"


//begin namespace block
namespace COMMON
{

SetClientDHParams::SetClientDHParams()
{
	this->_ConstructorID = -184262881;
	this->_ContentRelated = true;
}

SetClientDHParams::SetClientDHParams(TBigInt<128> nonce, TBigInt<128> server_nonce, FString encrypted_data)
{
	this->_ConstructorID = -184262881;
	this->_ContentRelated = true;
	this->nonce = nonce;
	this->server_nonce = server_nonce;
	this->encrypted_data = encrypted_data;
}
void SetClientDHParams::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.Write128Int(this->nonce);
	Writer.Write128Int(this->server_nonce);
	Writer.TGWriteString(this->encrypted_data);
}


void SetClientDHParams::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<PRIVATE::SetClientDHParamsAnswer*>(Reader.TGReadObject());
	this->_Responded = true;
}
SetClientDHParams::~SetClientDHParams()
{

}
}//end namespace block
