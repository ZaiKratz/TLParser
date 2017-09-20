#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"

//begin namespace block
namespace COMMON
{
class PhotoEmpty : public TLBaseObject
{
public:
	PhotoEmpty();
	PhotoEmpty(unsigned long long id);

	~PhotoEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
};
} //end namespace block
