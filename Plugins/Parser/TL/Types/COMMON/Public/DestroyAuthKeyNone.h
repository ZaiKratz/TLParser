#pragma once
#include "Engine.h"
#include "../../../Types/Private/DestroyAuthKeyRes.h"

#include "../../../Types/Private/DestroyAuthKeyRes.h"

//begin namespace block
namespace COMMON
{
class DestroyAuthKeyNone : public PRIVATE::DestroyAuthKeyRes
{
public:
	DestroyAuthKeyNone();
	~DestroyAuthKeyNone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
