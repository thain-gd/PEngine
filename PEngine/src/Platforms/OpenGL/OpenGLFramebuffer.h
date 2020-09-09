#pragma once

#include "PEngine/Renderer/Framebuffer.h"

namespace PEngine
{
	class OpenGLFramebuffer : public Framebuffer
	{
	private:
		uint32_t m_RendererID;
		uint32_t m_ColorAttachment, m_DepthAttachment;
		FramebufferSpecification m_Specification;

	public:
		OpenGLFramebuffer(const FramebufferSpecification& spec);
		virtual ~OpenGLFramebuffer();

		void Invalidate();

		void Bind() override;
		void Unbind() override;

		uint32_t GetColorAttachmentRendererID() const override { return m_ColorAttachment; }

		const FramebufferSpecification& GetSpecification() const override { return m_Specification; }
	};
}