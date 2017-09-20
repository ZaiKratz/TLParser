#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class RpcError : public TLBaseObject
{
public:
	RpcError();
	RpcError(int32 error_code, FString error_message);

	~RpcError();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 error_code;
	 FString error_message;
};
} //end namespace block
