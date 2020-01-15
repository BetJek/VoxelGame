#pragma once
#include <VulkanWrapper/VulkanWrapper.h>
#include "Engine/System.h"
#include "Engine/Renderer.h"

class RenderSystem : public System {
public:
    RenderSystem(uint32_t priority, Renderer& renderer);

    uint32_t getIndex() const { return m_index; }
    void submit(const vk::CommandBuffer& commandBuffer);
    void wait() const;

    void preUpdate(Clock& clock);
    void update(Clock& clock);

private:
    Renderer* m_renderer;
    std::vector<vk::Fence> m_fences;
    std::unique_ptr<vk::Semaphore> m_acquireSemaphore;
    std::unique_ptr<vk::Semaphore> m_renderFinishedSemaphore;
    std::vector<std::reference_wrapper<const vk::CommandBuffer>> m_commandBuffers;
    uint32_t m_index;
};