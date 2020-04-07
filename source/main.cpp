#include <QDebug>
#include <QGuiApplication>
#include <QOpenGLContext>
#include <QOffscreenSurface>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qWarning() << "OpenGLModuleType: " << QOpenGLContext::openGLModuleType() << "\n";
    qWarning() << "OpenGL thread support: " << QOpenGLContext::supportsThreadedOpenGL() << "\n";

    QOpenGLContext    m_cur_ctx;     ///< offscreen context
    m_cur_ctx.create();
    assert(m_cur_ctx.isValid() && "QtGpvfWrapper::m_cur_ctx is not valid");

    auto format = m_cur_ctx.format();
    qWarning() << "FORMAT: version=" << format.majorVersion() << "," << format.minorVersion() << ", profile=" << format.profile() << "\n";
    qWarning() << "OpenGLModuleType: " << QOpenGLContext::openGLModuleType() << "\n";
    qWarning() << "OpenGL thread support: " << QOpenGLContext::supportsThreadedOpenGL() << "\n";

    QOffscreenSurface m_cur_surface; ///< associated surface
    m_cur_surface.setFormat(format);
    //m_cur_surface.setScreen(m_cur_ctx.screen());
    m_cur_surface.create();
    assert(m_cur_surface.isValid() && "QtGpvfWrapper::m_cur_surface is not valid");

    //return app.exec();
}
//![0]
